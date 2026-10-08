---
name: run-batch
description: Run a batch of parallel match-functions workers, from the batch branch to the pull request.
disable-model-invocation: true
---

# Run a batch

You are the **orchestrator**. Four **workers** run at once, each matching its **claim** in its own worktree with the match-functions skill. You keep the four **slots** full, integrate each worker's branch into the batch branch, triage its **escalations**, and finish with one pull request to `main`. The measure is strictly matched code bytes per wall-clock hour for the whole batch, so an empty slot is the costliest thing in it.

Keep a batch log in the batch worktree's `build/batch-<N>.md` (`build/` is ignored, and a scratchpad does not survive a restart of Claude Code): one entry per report (claim, functions and bytes before and after, seconds, tokens, escalations, skill feedback). Anything that must outlive the batch goes to `docs/backlog.md`, the notes or the pull request.

## Steps

1. **Plan.** Run `date +%s` and keep the number. Read `docs/backlog.md`. Queue about three claims per slot: follow-ups first (their data and helpers are in place, so they give the cheapest bytes), then untouched units, largest first. A claim is one unit, or several small units (under about 5 KB of code each) for one worker. `python3 tools/match.py <unit>` gives a unit's state. Done when the queue is written in the log.

2. **Start.** From the main checkout on an up-to-date `main`, run `python3 tools/worktree.py match/batch-<N> --base main`. For each slot, run `python3 tools/worktree.py b<N>/<unit> --base match/batch-<N>`, then start the worker with the Agent tool (`subagent_type: general-purpose`, `model: opus`, `run_in_background: true`) and a prompt written from [`worker-prompt.md`](worker-prompt.md). Before a claim starts, apply the backlog's split proposals for its unit (step 4). Done when four workers are running.

3. **Integrate each report as it arrives.** Check that the worker left nothing running (`ps -Ao pid,command | grep <worktree>`, typically a permuter; kill it). Then run `python3 tools/integrate.py b<N>/<unit>` from the batch worktree, so tool changes made on the batch branch apply: it rebases the branch onto the batch branch, checks it, fast-forwards, runs `regress.py` against the old tip, and removes the worktree only if that passes.
   - Exit 2, a rebase conflict: in a shared header, keep both layouts as an anonymous `union` (the match-functions skill's **Claim**). When the conflict repeats over many commits, run `git merge match/batch-<N>` once in the worker's worktree instead. Then run `integrate.py` again.
   - Exit 1 because the rebased branch no longer builds: another worker, merged meanwhile, changed the same shared declaration another way. Give it both views as an anonymous `union` in the worker's worktree, commit there, and run `integrate.py` again.
   - Regress fails after the merge: fix forward on the batch branch, or reset it to the old tip that `integrate.py` prints.

   Log the report and refill the slot from the queue. Done when the branch is merged and the slot is busy again.

4. **Triage escalations.**
   - **Splits:** apply a proposal on the batch branch when its unit is next claimed, judged by the evidence rules in `docs/matching-notes.md` ("Unit boundaries"). New stubs are `void f(void) { return; }`, in reverse address order, with header prototypes; then `python3 tools/check_prototypes.py` must pass, since a prototype that contradicts another file's declaration breaks the build. Commit, and run `python3 tools/regress.py --base <previous tip>` in the batch worktree.
   - **Another unit's header** (placeholder prototypes, wrong types): pass it to that unit's next worker, or to the cleanup worker in step 5.
   - **Shared types, `symbols.txt` outside a claim, open questions:** add them to `docs/backlog.md`.
   - **A running worker affected** by a change (its claim's header changed under it): tell it with SendMessage.
   - **Skill feedback:** log it. The match-functions skill stays unchanged until the batch ends.

   Done when every escalation from the report is applied, assigned or in the backlog.

5. **End the batch.** After about three hours, stop refilling, and let the running workers finish. Then, on the batch branch:
   1. Start a cleanup worker (the task form of `worker-prompt.md`) with `python3 tools/check_prototypes.py`'s lists and the caller cleanups from the log, and integrate it. Start it in the first slot that frees in the last hour, leaving the running claims' files alone, rather than after the last report.
   2. Run `python3 tools/link_trial.py` in the batch worktree; commit the units it links.
   3. Apply the skill feedback that cost time, caused a mistake or recurred, in one commit; lessons go in the notes.
   4. Update `docs/backlog.md`: drop what was done, add the follow-ups and open escalations.
   5. Run `python3 tools/regress.py --base main`: its summary is the pull request's evidence, with the per-unit strict byte gains from the reports and the wall time.
   6. Ask the user before pushing. Push with the output sent to a file, since the pre-push hook runs `regress.py` and a pipe to `tail` breaks it. Open the pull request (CONTRIBUTING's evidence and AI disclosure), wait for `gh pr checks`, then run `python3 tools/publish_report.py` on its tip, so the Report run on `main` finds a report when it is merged.

   Done when the pull request's checks pass and its report is published.

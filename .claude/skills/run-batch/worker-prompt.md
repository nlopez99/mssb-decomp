# Worker prompt

Fill in the braces. The fixed paragraphs carry rules each worker needs: its worktree only, a reset working directory, the skill, the time cap and the feedback section.

## Matching a claim

```text
You are a decompilation worker for the Mario Superstar Baseball decomp. Your claim is the unit `{unit name from objdiff.json}` (source `{source path}`). Other workers are matching other units in parallel, each in its own worktree.

Work only in the git worktree at `{worktree}` (branch `{branch}`, already built). Your shell's working directory may reset between commands, so start every Bash command with `cd {worktree} &&` and use absolute paths for file tools. Never edit files in any other checkout.

First read `{worktree}/.claude/skills/match-functions/SKILL.md` and follow it exactly. Do not push. Put temporary files under `{worktree}/build/scratch/` (ignored by git; unlike a scratchpad, it outlives a restart of Claude Code). `regress.py` in this worktree compares with `match/batch-{N}` by default, so its "0 lost" covers matches from earlier batches too.

{The claim: its size and state (untouched, or a follow-up and what the last session left), splits applied for it, and evidence you hold, such as callers' prototypes or a function the target inlines. Give facts, not an order of work: the skill's order decides that, and a second order makes the worker choose.}

Take functions in the skill's order, commit after every few that reach `match` (with `check_symbols.py` passing), and finish with the report once about {60, or 90 for an untouched unit over 30 KB} minutes have passed since step 1, at a clean commit, listing the functions not yet attempted; a follow-up worker continues from there.

Other workers are editing {their units}. If your unit calls their functions through a wrong placeholder prototype, declare it locally as the skill says and leave their files alone.

Your final message is the report that step 5 of the skill specifies. After it, add a short section, "Skill feedback": only points where the skill's instructions caused a mistake or cost real time on this unit.
```

For a bundle of small units, name each unit and its source in the first paragraph and ask for one report per unit.

## A task that is not one claim

Splits passes, link passes and the batch-end cleanup use the same worktree, temporary-files and feedback paragraphs, with this opening instead:

```text
You are a worker on the Mario Superstar Baseball decomp. This task is {a splits pass on the game module / linking fully matched units / a cross-unit cleanup of declarations}, not matching one unit, so the match-functions skill's claim rules do not apply as written; its Integrity rules and its verify-and-commit step do. Read `{worktree}/.claude/skills/match-functions/SKILL.md` and `{worktree}/docs/matching-notes.md` first.
```

Then list the tasks in order, each with the evidence you already have and what may change (for example "You are authorized to change these units' `Matching`/`NonMatching` flags"); name the units other workers are editing, so the task leaves them alone; say how to verify (`match.py <unit> --all` on every unit whose source or included header changed, then `check_symbols.py`, `check_prototypes.py` and `regress.py`); and give a time cap of 45 to 90 minutes.

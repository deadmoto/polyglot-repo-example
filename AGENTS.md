# Polyglot Repo Example

## Agent Instructions

- Debrief the user when the work is done. Summarize new learned concepts, methods, and principles that may be useful for future agents working in this repo or working elsewhere with the tools used in this repo.
- Change versions one at a time. Do not upgrate multiple tools or dependencies at once. Validate build after each step.

## Nix

- Always clear nix cache after making changes to shell.nix

## Bazel

- Do not change versions of external dependencies unless asked. Ask for confirmation if an upgrade is required.
- Do not use bazelisk. Only use Bazel provided by Nix.
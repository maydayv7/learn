#! /usr/bin/env nix
#! nix shell nixpkgs#bash nixpkgs#git nixpkgs#git-filter-repo -c bash

REMOTE_URL=$(git remote get-url origin)

git filter-repo --message-callback '
msg_str = message.decode("utf-8")
lines = msg_str.splitlines()
if not lines:
  return message

subject = lines[0]
if ":" not in subject:
  if subject.strip().endswith("- LeetHub"):
    return b"chore(LC): Create Problem README"
return message
' --force

git remote add origin "$REMOTE_URL"
git push origin --force --all -u

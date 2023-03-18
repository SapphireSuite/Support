# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Clear console.
clear

# Save all current pending modifications.
git stash

# Save current head commit.
curr_commit=`git rev-parse HEAD`

git subtree add --prefix .subtree https://github.com/SapphireSuite/SourceRepository.git main --squash

# Reset head to previous current commit to remove auto merge.
git reset $curr_commit

# Remove ReadMe to avoid override.
rm -rf .subtree/README.md

# Copy all files from Source Repository to this
rsync -a .subtree/ ./

# Remove temp subtree sources
rm -rf .subtree/

# Update (CMake) submodules
git submodule update

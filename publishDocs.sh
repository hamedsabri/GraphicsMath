#!/bin/bash

set -euxo pipefail

# Check out the master branch and freshly build the documentation
# and install to /tmp
git checkout master
rm -rfv ./build
mkdir -p /tmp/GraphicsMathDocs
rm -rfv /tmp/GraphicsMathDocs
./build.sh /tmp/GraphicsMathDocs

# Checkout the gh-pages branch, remove all files, and copy the
# installed documentation into the repo root.
git checkout gh-pages
rm -rf *
cp -r /tmp/GraphicsMathDocs/docs/doxygen_docs/html/* ./

# Stage and commit the changes, optionally rebasing (interactively).
git add *
git commit -a -m "Updated documentation."
git rebase --interactive --root

# Then, force push the changes (living dangerously).
git push origin -f

# Switch back to the master branch.
git checkout master

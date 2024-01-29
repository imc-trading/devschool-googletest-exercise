#!/bin/bash

set -euo pipefail

REVISION=${1:-HEAD}
SHA=$(git rev-parse -q --short "$REVISION^{commit}") || { echo "Failed to find revision $REVISION. Aborting"; exit 1; }
PREFIX=cpp-google-test-exercise
NAME=$PREFIX-$REVISION-$SHA

echo "Creating archive of content at $NAME.tar.gz from $REVISION ($SHA)"

# Note: files marked with export-ignore in .gitattributes will not be included in the archive.
git archive --format tar --prefix=$PREFIX/ -o $NAME.tar.gz $SHA

cat <<EOF

WARNING: README.md contains a link to Compiler Explorer for those that cannot get Bazel working locally.
         Ensure this link is up to date before providing to trainees.
EOF


#!/bin/bash

if [[ $GITHUB_TOKEN ]]; then
  npm run prebuild-release -- -u "$GITHUB_TOKEN" -t $TRAVIS_NODE_VERSION -r node
  npm run prebuild-release -- -u "$GITHUB_TOKEN" -t $TRAVIS_NODE_VERSION -r electron
fi

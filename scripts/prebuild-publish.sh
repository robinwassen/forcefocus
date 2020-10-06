#!/bin/bash

if [[ $GITHUB_TOKEN ]]; then
  npm run prebuild-release -- -u "$GITHUB_TOKEN" -t $TRAVIS_NODE_VERSION.0.0 -r node
  npm run prebuild-release -- -u "$GITHUB_TOKEN" -t $TRAVIS_NODE_VERSION.0.0 -r electron
fi

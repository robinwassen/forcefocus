@echo off

if %APPVEYOR_REPO_BRANCH% == master (
  if %GITHUB_TOKEN% neq "" (
    npm run prebuild-release -- -u %GITHUB_TOKEN% -t %TRAVIS_NODE_VERSION% -r node
    npm run prebuild-release -- -u %GITHUB_TOKEN% -t %TRAVIS_NODE_VERSION% -r electron
  )
)

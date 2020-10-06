@echo off

if %APPVEYOR_REPO_BRANCH% == master (
  if %GITHUB_TOKEN% neq "" (
    npm run prebuild-release -- -u %GITHUB_TOKEN% -t %1 -r node
    npm run prebuild-release -- -u %GITHUB_TOKEN% -t %1 -r electron
  )
)

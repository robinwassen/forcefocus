<!-- Make sure you edit doc/README.hbs rather than README.md because the latter is auto-generated -->

forcefocus
=========

> Node module that allows you to steal focus from other windows in Windows.

[![npm](https://img.shields.io/npm/dw/forcefocus.svg)](https://npmjs.com/package/forcefocus)
[![NpmVersion](https://img.shields.io/npm/v/forcefocus.svg)](https://npmjs.com/package/forcefocus)
[![NpmLicense](https://img.shields.io/npm/l/forcefocus.svg)](https://npmjs.com/package/forcefocus)
[![AppVeyor branch](https://img.shields.io/appveyor/ci/robinwassen/forcefocus/master.svg?logo=appveyor)](https://ci.appveyor.com/project/robinwassen/forcefocus)
[![Travis (.org) branch](https://img.shields.io/travis/robinwassen/forcefocus/master.svg?logo=travis)](https://travis-ci.org/robinwassen/forcefocus)

Microsoft changed the implementation of [SetFocus()](https://msdn.microsoft.com/en-us/library/windows/desktop/ms646312(v=vs.85).aspx) to only allow an app to grant focus to other windows if it currenly holds the focus. If an app that does not have the focus tries to take it, the taskbar will just flash rather than focusing the window. These changes was probably done to improve the user experience, so users would not be disturbed by the focused application suddenly switching.

This module circumvents the restrictions in SetFocus() and allows any window to steal the focus.

It reuses the Electron built-in focus on other platforms.

Installation
------------

Install `forcefocus` by running:

```sh
$ npm install --save forcefocus
```

Native binaries for win, mac and linux are prebuilt and downloaded when the module is installed.

Documentation
-------------

<a name="module_forcefocus.focusWindow"></a>

### forcefocus.focusWindow(window)
**Kind**: static method of [<code>forcefocus</code>](#module_forcefocus)  
**Summary**: Force focus on a Window  
**Access**: public  

| Param | Type | Description |
| --- | --- | --- |
| window | <code>BrowserWindow</code> | Window to focus |

**Example**  
```js
var forceFocus = require('forcefocus');
var currentWindow = require('electron').remote.getCurrentWindow();

forceFocus.focusWindow(currentWindow);
```

Example application
-------------

An example application is located in the `/example/` dir, start it by running:

```sh
$ npm run example
```

Contribute
----------

Feel free to contribute to this module.

Before submitting a PR, please make sure that the linter runs without any warning:

```sh
$ npm run lint
```

License
-------

The project is licensed under the Apache 2.0 license.

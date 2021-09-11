'use strict';

const {
  app, ipcMain, BrowserWindow
} = require('electron');
const path = require('path');

let mainWindow;

/**
 * @summary Creates the main window
 * @function
 * @public
 *
 */
const createWindow = function() {
  const windowProperties = {
    width: 800,
    height: 600,
    webPreferences: {
      enableRemoteModule: false,
      contextIsolation: true,
      nodeIntegration: false,
      nativeWindowOpen: true,
      webSecurity: true,
      preload: path.join(__dirname, 'preload.js')
    }
  };

  mainWindow = new BrowserWindow(windowProperties);
  mainWindow.loadFile('index.html');

  mainWindow.on('closed', function() {
    mainWindow = null;
  });
};

app.on('ready', createWindow);

app.on('window-all-closed', function() {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});

app.on('activate', function() {
  if (mainWindow === null) {
    createWindow();
  }
});

const forceFocus = require('..');

ipcMain.handle('force-focus', () => {
  forceFocus.focusWindow(mainWindow);
});

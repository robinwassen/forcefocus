'use strict';

const {
  contextBridge, ipcRenderer
} = require('electron');

contextBridge.exposeInMainWorld(
  'forcefocus',
  {
    focusWindow: () => {
      return ipcRenderer.invoke('force-focus');
    }
  }
);

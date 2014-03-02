path = require('path');

dirname = path.relative('.', __dirname);
console.log(path.join(dirname, 'binding.gyp:native_mate'));

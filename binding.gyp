{
  'target_defaults': {
    'default_configuration': 'Release',
    'configurations': {
      'Debug': {
        'msvs_settings': {
          'VCCLCompilerTool': { 
            'RuntimeTypeInfo': 'true',
            'RuntimeLibrary': 0,
            'ExceptionHandling': 1,
            'AdditionalOptions': ['/EHsc', '/GR']
            },
        }
      }, # Debug
      'Release': {
        'msvs_settings': {
          'VCCLCompilerTool': { 
            'RuntimeTypeInfo': 'true',
            'RuntimeLibrary': 0,
            'ExceptionHandling': 1,
            'AdditionalOptions': ['/EHsc', '/GR'],
            },
        }, # Release
      }
    }
  },
  "targets": [
    {
      "target_name": "nosleep",
      "sources": [ "no-sleep.cc" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "dependencies": ["<!(node -p \"require('node-addon-api').gyp\")"],
      "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"]
    }
  ]
}

{
  "targets": [
    {
      "target_name": "nosleep",
      "conditions": [
        ["OS=='win'", {
          "sources": [ "no-sleep.cc" ]
        }, {
          "type": "none"
        }]
      ]
    }
  ]
}

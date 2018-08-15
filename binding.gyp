{
  "targets": [
    {
      "target_name": "forcefocus",
      "sources": [
        "src/bindings.cc"
      ],
      "conditions": [
        [
          "OS==\"win\"",
          {
            "sources": ["src/forcefocus_win.cc"]
          }
        ],
        [
          "OS!=\"win\"",
          {
            "sources": ["src/forcefocus_noop.cc"]
          }
        ]
      ]
    }
  ]
}

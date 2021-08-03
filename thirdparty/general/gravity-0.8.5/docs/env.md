## ENV
ENV is a class than enables to interact with environmental variables

### Class methods
```swift
// read an env variable
var value = ENV.get("VAR_NAME")

// write an env value
ENV.set("VAR_KEY", "VAR_VALUE")

// list all env variables
var list = ENV.keys()
```

### Class Constants
```swift
var max_arg = ENV.argc - 1 
var my_arg = ENV.argv[max_arg]
```

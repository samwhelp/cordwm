

# Mousebind


## button definitions
| click         | event mask |  button    |  function     | argument      |
| ------------- | ---------- | ---------- | ------------- | ------------- |
| ClkLtSymbol   |   0        |  Button1   | setlayout     | 0             |
| ClkLtSymbol   |   0        |  Button3   | setlayout     | layouts[2]    |
| ClkWinTitle   |   0        |  Button2   | zoom          | 0             |
| ClkStatusText |   0        |  Button2   | spawn         | termcmd       |
| ClkClientWin  |   win +    |  Button1   | moveorplace   | 0             |
| ClkClientWin  |   win +    |  Button2   | togglefloating| 0             |
| ClkClientWin  |   win +    |  Button3   | resizemouse   | 0             |
| ClkClientWin  |  ctrl +    |  Button1   | dragmfact     | 0             |
| ClkClientWin  |  ctrl +    |  Button3   | dragcfact     | 0             |
| ClkTagBar     |  0         |  Button1   | view          | 0             |
| ClkTagBar     |  0         |  Button3   | toggleview    | 0             |
| ClkTagBar     |  win +     |  Button1   | tag           | 0             |
| ClkTagBar     |  win +     |  Button3   | toggletag     | 0             |
| ClkTabBar     |  0         |  Button1   | focuswin      | 0             |
| ClkTabBar     |  0         |  Button1   | focuswin      | 0             |
| ClkTabPrev    |  0         |  Button1   | movestack     |-1             |
| ClkTabNext    |  0         |  Button1   | movestack     |+1             |
| ClkTabClose   |  0         |  Button1   | killclient    | 0             |

# Keycode Syntax

## Printing a string:
  The keyword ``` PR: ```is used when printing a string. Anything that follows afterwards is to be typed in via keyboard. The string to be typed ends when a newline is encountered
  ``` PR: <String goes here> ```
  Example:
``` PR: Welcome to Hacknight ```
prints ``` Welcome to Hacknight ```.
## Pressing Two keys simultaneously:
   ## Shift plus characters
   ``` SHIFT+x ``` where x could be any character (a-z). Note the lack of spaces.
  ## Control plus character
   ``` CTRL+x ``` where x could be any character (a-z). Note the lack of spaces.
  ## Windows plus character
   ``` WIN+x``` where x could be any character (a-z). Note the lack of spaces.
## Pressing Three Keys at once:
  ## Ctrl plus Shift plus character
   ```CTRL+SHIFT+x``` where x could be any character (a-z). Note the lack of spaces.
      (Coluld also be ```SHIFT+CTRL+x```)
## Pressing Enter
```ENTER``` should emulate pressing the enter key
## Arrow Keys
```ARR+U``` --> Up arrow
```ARR+D``` --> Down arrow
```ARR+L``` --> Left arrow
```ARR+R``` --> Right arrow
## Other stuff to note:
1. Each new command gets a new line
2. The code starts with ```START```, ends with ```FIN```

## Sample Code
```
START
WIN+r
PR: notepad
ENTER
END
```
This code should open the notepad

,>,       Read the first digit and store it in cell 1
[          Start a loop
  -        Decrement the first digit to convert it to its numerical value
  ,>,      Read the second digit and store it in cell 2
  -        Decrement the second digit to convert it to its numerical value
  +        Add the two digits by incrementing the first digit
  [->+<]   Move the result to cell 1 and reset cell 2 to 0
  <.       Print the result
]

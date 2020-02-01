main = do
  n <- getLine
  nums <- getLine
  print $ sum (map (read::String->Int) (words nums))

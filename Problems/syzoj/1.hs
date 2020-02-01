main = do 
  str <- getLine
  print $ let a = (map (read::String->Int) (words str)) in a + b

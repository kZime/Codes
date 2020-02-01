fc x = if x == 0 then 1 else (x * fc (x - 1))
main = do
  x <- getLine
  print $ sum (map fc [1..(read x::Integer)])

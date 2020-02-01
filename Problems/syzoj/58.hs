isPrime x
  | x < 2 = True
  | filter (\k -> mod x k == 0) [2..x-1] /= [] = False
  | True = True

main = do
  str <- getLine
  let x = read str :: Int
  let res = isPrime x
  if res then putStrLn "Yes"
         else putStrLn "No"

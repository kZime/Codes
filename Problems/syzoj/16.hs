import Data.List
join (x:xs) 
  | xs == [] = show x
  | True     = (show x) ++ " " ++ join xs
main = do
  n <- getLine
  str <- getLine
  putStrLn $ join $ sort $ map (read::String->Int) (words str)

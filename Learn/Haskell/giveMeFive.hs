import Data.List
{-
giveMeFive ll
  | ll == [] = []
  | True = let ((i, x):xs) = ll in
             if x `rem` 5 == 0 then x : giveMeFive xs
                               else giveMeFive xs
-}
-- ugly...

giveMeFive xs = map snd $ filter (\(i,x) -> x `rem` 5 == 0) $ zip [1..] xs

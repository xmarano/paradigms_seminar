{-
-- EPITECH PROJECT, 2025
-- pushswap.hs
-- File description:
-- RUSH 01
-}
import Data.List (sort)
import Data.Char (isDigit)
import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(..))

rotate :: [Int] -> [Int]
rotate [] = []
rotate (x:xs) = xs ++ [x]

reverseRotate :: [Int] -> [Int]
reverseRotate [] = []
reverseRotate x = last x : init x

pushBToA :: [Int] -> [Int] -> ([Int], [Int])
pushBToA la (x:lb) = (x:la, lb)
pushBToA la lb = (la, lb)

pushAToB :: [Int] -> [Int] -> ([Int], [Int])
pushAToB (x:la) lb = (la, x:lb)
pushAToB la lb = (la, lb)

calcul :: String -> ([Int], [Int]) -> ([Int], [Int])
calcul "sa" (x:y:xs, lb) = (y:x:xs, lb)
calcul "sb" (la, x:y:ys) = (la, y:x:ys)
calcul "sc" (la, lb) = calcul "sa" (calcul "sb" (la, lb))
calcul "pa" (la, lb) = (pushBToA la lb)
calcul "pb" (la, lb) = (pushAToB la lb)
calcul "ra" (la, lb) = (rotate la, lb)
calcul "rb" (la, lb) = (la, rotate lb)
calcul "rr" (la, lb) = (rotate la, rotate lb)
calcul "rra" (la, lb) = (reverseRotate la, lb)
calcul "rrb" (la, lb) = (la, reverseRotate lb)
calcul "rrr" (la, lb) = (reverseRotate la, reverseRotate lb)
calcul operation listes = listes

split :: [String] -> ([Int], [Int]) -> ([Int], [Int])
split operations listes = foldl (flip calcul) listes operations

parsError :: String -> IO ()
parsError "sa"  = return ()
parsError "sb"  = return ()
parsError "sc"  = return ()
parsError "pa"  = return ()
parsError "pb"  = return ()
parsError "ra"  = return ()
parsError "rb"  = return ()
parsError "rr"  = return ()
parsError "rra" = return ()
parsError "rrb" = return ()
parsError "rrr" = return ()
parsError operation = exitWith (ExitFailure 84)

splitError :: [String] -> IO ()
splitError operations =  mapM_ parsError operations

isSorted :: [Int] -> Bool
isSorted x = x == sort x

isInt :: String -> Bool
isInt "" = False
isInt ('-':xs) = all isDigit xs
isInt str = all isDigit str

checkSorted :: [Int] -> [Int] -> IO ()
checkSorted l_a l_b =
    if isSorted l_a && null l_b
        then print "OK"
        else print $ "KO: (" ++ show l_a ++ "," ++ show l_b ++ ")"

main :: IO ()
main = do
    args <- getArgs
    if length args < 1 || not (all isInt args) then exitWith (ExitFailure 84)
    else do
        let la = map read args :: [Int]
        operations_line <- getLine
        let operations = words operations_line
        splitError operations
        let (l_a, l_b) = split operations (la, [])
        checkSorted l_a l_b

{-
-- EPITECH PROJECT, 2025
-- task13.hs
-- File description:
-- DAY 02
-}
import Data.Char (isDigit)
import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(..))

isInt :: String -> IO ()
isInt "" = exitWith (ExitFailure 84)
isInt ('-':xs)
    | all isDigit xs = return ()
    | otherwise = exitWith (ExitFailure 84)
isInt str
    | all isDigit str = return ()
    | otherwise = exitWith (ExitFailure 84)

calcul :: Int -> Char -> Int -> IO ()
calcul a '+' c = print (a + c)
calcul a '-' c = print (a - c)
calcul a '*' c = print (a * c)
calcul a '/' 0 = exitWith (ExitFailure 84)
calcul a '/' c = print (a `div` c)
calcul a '%' 0 = exitWith (ExitFailure 84)
calcul a '%' c = print (a `mod` c)
calcul _ _ _ = exitWith (ExitFailure 84)

main :: IO ()
main = do
    args <- getArgs
    if length args /= 3 then exitWith (ExitFailure 84)
    else do
        useless <- getArgs
        let [a, b, c] = args
        isInt a
        isInt c
        calcul (read a) (head b) (read c)

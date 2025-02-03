{-
-- EPITECH PROJECT, 2025
-- DoOp.hs
-- File description:
-- DAY 02
-}
import Data.Char (isLetter)
import System.Environment (getArgs)

myElem :: Eq a => a -> [ a ] -> Bool
myElem x [] = False
myElem x (y:ys)
    |   x == y = True
    |   otherwise = myElem x ys

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [ a ] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:xs) 0 = Just x
safeNth (x:xs) n
    |   n < 0     = Nothing
    |   otherwise = safeNth xs (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc (Just x) = Just (x + 1)
safeSucc Nothing = Nothing

myLookup :: Eq a => a -> [( a , b ) ] -> Maybe b
myLookup x [] = Nothing
myLookup x ((a, b):ys)
    |   x == a = Just b
    |   otherwise = myLookup x ys

maybeDo :: ( a -> b -> c ) -> Maybe a -> Maybe b -> Maybe c
maybeDo f (Just x) (Just y) = Just (f x y)
maybeDo _ _ _ = Nothing

readInt :: [ Char ] -> Maybe Int
readInt [] = Nothing
readInt str
    |   any isLetter str = Nothing
    |   otherwise = Just (read str :: Int)

getLineLength :: IO Int
getLineLength = do
    str <- getLine
    return (length str)

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >> return (length str)

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox x
    |   x <= 0 = return ()
printBox x =
    putStrLn ("+" ++ replicate ((2 * x) - 2) '-' ++ "+")
    >> printMiddle (x - 2) (replicate ((2 * x) - 2) ' ')
    >> putStrLn ("+" ++ replicate ((2 * x) - 2) '-' ++ "+")

printMiddle :: Int -> [Char] -> IO ()
printMiddle 0 str = return ()
printMiddle x str = do
    useless <- getArgs
    putStrLn ("|" ++ str ++ "|")
    printMiddle (x - 1) str

concatLines :: Int -> IO String
concatLines x
    |   x <= 0 = return ("")
    |   otherwise = loop x ""

loop :: Int -> String -> IO String
loop 0 str = return str
loop n str = do
    str2 <- getLine
    loop (n - 1) (str ++ str2)

getInt :: IO (Maybe Int)
getInt = do
    str <- getLine
    return (readInt str)

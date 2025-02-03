{-
-- EPITECH PROJECT, 2025
-- My.hs
-- File description:
-- DAY 01
-}

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x
    |   x < 0 = x * (-1)
    |   x > 0 = x

myMin :: Int -> Int -> Int
myMin x y
    | x > y = y
    | y > x = x

myMax :: Int -> Int -> Int
myMax x y
    | x < y = y
    | y < x = x

myTuple :: a -> b -> (a , b )
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a , b , c )
myTruple a b c = (a, b, c)

myFst :: (a , b ) -> a
myFst (a, b) = a

mySnd :: (a , b ) -> b
mySnd (a, b) = b

mySwap :: (a , b) -> (b , a )
mySwap (a, b) = (b, a)

myHead :: [ a ] -> a
myHead [] = error "error"
myHead (a:_)  = a

myTail :: [ a ] -> [ a ]
myTail [] = error "error"
myTail (_:a)  = a

myLength :: [ a ] -> Int
myLength [] = 0
myLength (a:as) = 1 + myLength as

myNth :: [ a ] -> Int -> a
myNth [] _ = error "index too large"
myNth (x:xs) 0 = x
myNth (x:xs) n
    |   n < 0     = error "index negative"
    |   otherwise = myNth xs (n - 1)

myTake :: Int -> [a] -> [a]
myTake n (x:xs)
    |   n < 0 = error "index negative"
    |   myLength (x:xs) == 0 = []
    |   n > myLength (x:xs) = (x:xs)
    |   n > 0 = x : myTake (n - 1) xs
    |   otherwise = []

myDrop :: Int -> [a] -> [a]
myDrop n (x:xs)
    |   myLength (x:xs) < n = []
    |   myLength (x:xs) == 0 = []
    |   myLength (x:xs) == n = []
myDrop 1 (x:xs) = xs
myDrop n (x:xs) = myDrop (n - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend a b
    |   myLength a == 0 = b
    |   myLength b == 0 = a
myAppend (x:ab) cd = x : myAppend ab cd

myReverse :: [ a ] -> [ a ]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [ a ] -> [ a ]
myInit [] = error "empty list"
myInit [a] = []
myInit (x:z) = x : myInit z

myLast :: [ a ] -> a
myLast [] = error "empty list"
myLast [a] = a
myLast (x:z) = myLast z

myZip :: [ a ] -> [ b ] -> [( a , b ) ]
myZip [] b = []
myZip a [] = []
myZip (x:xs) (z:zs) = (x, z) : myZip xs zs

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y):xs) = (x : myFst (myUnzip xs), y : mySnd (myUnzip xs))

myMap :: ( a -> b ) -> [ a ] -> [ b ]
myMap a [] = []
myMap f (x:y) = f x : myMap f y

myFilter :: ( a -> Bool ) -> [ a ] -> [ a ]
myFilter a [] = []
myFilter f (x:y)
    |   f x == True = x : myFilter f y
    |   otherwise = myFilter f y
    
myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl a ac [] = ac
myFoldl op acc (x:xs)
    | myLength (x:xs) == 0 = acc
    | otherwise = myFoldl op (op acc x) xs

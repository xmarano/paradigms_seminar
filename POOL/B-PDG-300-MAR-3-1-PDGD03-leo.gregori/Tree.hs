{-
-- EPITECH PROJECT, 2025
-- Tree.hs
-- File description:
-- DAY 03
-}

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show)

instance Functor Tree where
    fmap _ Empty = Empty
    fmap f (Node left value right) =
        Node (fmap f left) (f value) (fmap f right)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = (Node Empty a Empty)
addInTree new_x (Node left x right)
    | new_x < x = Node (addInTree new_x left) x right
    | otherwise = Node left x (addInTree new_x right)

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (x:xs) = addInTree x (listToTree xs)

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node left x right) =
    treeToList left ++ [x] ++ treeToList right

treeSort :: Ord a => [a] -> [a]
treeSort [] = []
treeSort x = treeToList (listToTree x)

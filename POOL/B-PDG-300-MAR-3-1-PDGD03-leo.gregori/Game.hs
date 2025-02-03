{-
-- EPITECH PROJECT, 2025
-- Game.hs
-- File description:
-- DAY 03
-}

data Item = Sword | Bow | MagicWand deriving (Eq)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving (Eq)

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just item)) = "witch holding a " ++ show item

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = Just (createMummy)
create "doomed archer" = Just (createArcher)
create "dead knight" = Just (createKnight)
create "witch" = Just (createWitch)
create "sorceress" = Just (createSorceress)
create str = Nothing

equip :: Item -> Mob -> Maybe Mob
equip item2 (Skeleton item) = Just (Skeleton item2)
equip item2 (Witch item) = Just (Witch (Just item2))
equip item mob = Nothing

class HasItem item where
    getItem :: item -> Maybe Item
    hasItem :: item -> Bool
    hasItem x = if getItem x == Nothing then True else False

instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton item) = Just item
    getItem (Witch Nothing) = Nothing
    getItem (Witch (Just item)) = Just item

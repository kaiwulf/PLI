module Main (main) where

import Test.Hspec

main :: IO ()
main = hspec $
  describe "harness" $
    it "runs" $ True `shouldBe` True

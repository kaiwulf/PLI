module Main (main) where

import System.Exit (exitFailure)
import System.IO (hPutStrLn, stderr)

main :: IO ()
main = do
  hPutStrLn stderr "pl1c: no front-end stages implemented yet"
  exitFailure

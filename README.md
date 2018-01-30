Catalan number comparison
===

Goal
---

This project aims to compare the time elapsed for calculating the
Catalan number `C_n = (2n)!/(n! (n+1)!)`.

Languages
---

- C (with GNU MultiPrecision Library)
  - `catlist`: List first `N` Catalan numbers.  (Use `N ≤ 4000` to
      avoid hanging your device.)
  - `catalanNumber`: `N = 100000` has been successfully tested.  Try
      largest `N` at your risk.
- GNU Octave: copied from Rosetta code (Use `N ≤ 60` to avoid
    precision lost)

My results
---

- C
- - `catlist`: `N = 2000` takes 2 seconds.
- - `catalanNumber`: `N = 100000` takes 3 seconds.
- GNU Octave: `N = 60` takes 0.6 second.

License
---

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

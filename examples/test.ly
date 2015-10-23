\version "2.16.0"
\include "deutsch.ly"

\header {
  title = "Rondo Alla Turca"
  subtitle = "Turkish March"
  composer = "W. A. Mozart"
  piece = "Allegretto"
  mutopiatitle = "Sonate Opus KV 331 - Rondo Alla Turca"
  mutopiacomposer = "MozartWA"
  mutopiainstrument = "Piano"
  mutopiaopus = "KV 331"
  style = "Classical"
  license = "Public Domain"
  source = "IMSLP"
}


\score {
  \new PianoStaff
  <<
    \new Staff {
      \time 2/4
      \transpose c c'' {
	  h,16-4( a, gis, a,-1 |
	  c8)-.-3 r d16-3( c h, c |
	  e8)-.-4 r f16-4( e dis e-1 |
	  h-4 a gis a h a gis a |
	  c'4)\accent a8-.-2 c'-.-4 |
	  \grace { g!32[( a)] } h8-.-> <fis a>-.-2-4 <e g>-. <fis a>-. |
	  \grace { g32[( a)] } h8-.-> <fis a>-.-2-4 <e g>-. <fis a>-. |
	  \grace { g32[( a)] } h8-.-> <fis a>-.-4 <e g>-. <dis fis>-.-2-4 |
	  e4
	  }
    }
  >>
  \layout {}
  \midi {}
}
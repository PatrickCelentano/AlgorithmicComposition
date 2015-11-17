\version "2.16.0" 

\header{
	title = "Title here"
	subtitle = "Subtitle here"
} 

\score{
	<<
		\new PianoStaff = "piano" <<
			\new Staff = "upper"
			\absolute{
				\clef treble
				c' 
			}
			\new Staff = "lower"
			\absolute{
				\clef bass
				
			}
		>>
	>>
	\midi{ }
	\layout{ }
}

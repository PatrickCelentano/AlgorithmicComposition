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
				\numericTimeSignature
				\time3/4
				e'4 b'4 b'16 e'16 b'16 gis'16 a'16 fis'16 cis''16 fis'16 gis''4 e'8 a''8 e'4 dis''4 dis''4 fis''4 a'4 cis''16 cis''16 a'16 e''16 cis''16 a'16 cis''16 cis''16 dis''4 gis'16 e'16 e'16 e'16 fis''2. gis'4 fis''4 gis'4 b'2. e''16 e''16 e''16 e''16 cis''4 gis''4 a'4 cis''4 cis''4 e'4 dis''4 cis''16 cis''16 cis''16 gis''16 e''16 fis''16 cis''16 b'16 gis'4 b'16 b'16 dis''16 a''16 gis'4 fis''8 gis'8 b'4 cis''4 a'4 cis''4 dis''8 b'8 cis''16 gis''16 gis''16 e''16 b'4 cis''4 b'16 e''16 a'16 cis''16 fis'16 cis''16 a'16 e''16 fis'4 b'4 cis''4 fis''8 e''8 e'16 b'16 b'16 gis'16 dis''4 gis'2. cis''4 b'4 dis''4 gis''8 cis''8 e''16 cis''16 e''16 b'16 e''16 b'16 b'16 b'16 b'8 gis'8 e''8 gis''8 e''4 gis'8 a'8 cis''4 e''8 e''8 b'4 b'4 b'16 fis''16 gis''16 gis'16 e''2. fis''8 cis''8 fis''4 cis''8 gis'8 gis''8 e''8 dis''8 gis''8 dis''8 gis'8 dis''4 fis''4 fis''8 b'8 cis''16 e''16 cis''16 gis''16 cis''4 gis'8 e'8 fis''16 b'16 cis''16 a'16 e''4 fis'4 gis''2. a'4 cis''8 a''8 b'4 cis''2. dis''2. gis'4 b'4 b'4 a''16 a''16 fis''16 fis''16 e''4 e''4 e''8 e''8 cis''4 e''4 fis''4 cis''4 cis''8 cis''8 gis'4 a'4 fis'4 gis''4 cis''8 gis''8 e''16 e''16 e''16 cis''16 
			}
			\new Staff = "lower"
			\absolute{
				\clef bass
				\numericTimeSignature
				\time3/4
				<e gis b >2. <a cis e >16 <fis a cis >16 <cis e gis >16 <fis a cis >16 <cis e gis >8 <b dis fis >8 <e gis b >8 <dis fis a >8 <e gis b >4 <b dis fis >16 <cis e gis >16 <fis a cis >16 <cis e gis >16 <b dis fis >16 <e gis b >16 <b dis fis >16 <e gis b >16 <dis fis a >8 <cis e gis >8 <a cis e >8 <fis a cis >8 <cis e gis >16 <a cis e >16 <fis a cis >16 <cis e gis >16 <a cis e >4 <b dis fis >4 <e gis b >4 <b dis fis >8 <cis e gis >8 <fis a cis >4 <a cis e >8 <b dis fis >8 <e gis b >4 <dis fis a >4 <e gis b >4 <b dis fis >4 <e gis b >16 <dis fis a >16 <cis e gis >16 <a cis e >16 <fis a cis >4 <cis e gis >2. <a cis e >2. <e gis b >4 <dis fis a >4 <cis e gis >4 <a cis e >16 <b dis fis >16 <cis e gis >16 <b dis fis >16 <e gis b >8 <a cis e >8 <e gis b >8 <dis fis a >8 <e gis b >4 <b dis fis >8 <e gis b >8 <b dis fis >8 <cis e gis >8 <fis a cis >8 <cis e gis >8 <fis a cis >4 <cis e gis >4 <b dis fis >4 <cis e gis >4 <gis b dis >4 <cis e gis >4 <b dis fis >16 <cis e gis >16 <fis a cis >16 <a cis e >16 <fis a cis >8 <a cis e >8 <fis a cis >16 <cis e gis >16 <fis a cis >16 <a cis e >16 <b dis fis >4 <cis e gis >4 <b dis fis >16 <e gis b >16 <a cis e >16 <b dis fis >16 <e gis b >4 <dis fis a >4 <e gis b >2. <a cis e >4 <e gis b >16 <dis fis a >16 <e gis b >16 <a cis e >16 <b dis fis >4 <cis e gis >16 <gis b dis >16 <a cis e >16 <b dis fis >16 <cis e gis >16 <fis a cis >16 <a cis e >16 <e gis b >16 <a cis e >16 <b dis fis >16 <e gis b >16 <b dis fis >16 <e gis b >4 <a cis e >16 <fis a cis >16 <cis e gis >16 <fis a cis >16 <cis e gis >16 <gis b dis >16 <cis e gis >16 <b dis fis >16 <e gis b >8 <a cis e >8 <fis a cis >4 <a cis e >4 <e gis b >4 <b dis fis >4 <e gis b >16 <b dis fis >16 <cis e gis >16 <gis b dis >16 <a cis e >4 <b dis fis >4 <cis e gis >4 <b dis fis >16 <e gis b >16 <a cis e >16 <e gis b >16 <b dis fis >4 <cis e gis >8 <gis b dis >8 <cis e gis >4 <b dis fis >8 <cis e gis >8 <b dis fis >8 <e gis b >8 <b dis fis >2. <cis e gis >4 <a cis e >4 <e gis b >4 <b dis fis >16 <e gis b >16 <a cis e >16 <fis a cis >16 <cis e gis >4 <fis a cis >4 <cis e gis >4 <gis b dis >16 <cis e gis >16 <fis a cis >16 <cis e gis >16 <a cis e >4 <fis a cis >4 <a cis e >16 <e gis b >16 <dis fis a >16 <cis e gis >16 <b dis fis >4 <cis e gis >2. <b dis fis >2. <e gis b >2. <dis fis a >4 <cis e gis >4 <a cis e >8 <fis a cis >8 <cis e gis >2. <b dis fis >4 <cis e gis >4 <a cis e >4 <e gis b >4 <a cis e >4 <fis a cis >4 <cis e gis >2. 
			}
		>>
	>>
	\midi{ }
	\layout{ }
}

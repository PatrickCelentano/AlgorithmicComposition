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
				c'8 f'8 b'8 f'8 c'8 d'8 f'8 ees'8 d'8 f'8 aes'8 g'8 g'8 g'8 aes'8 f'8 d'8 ees'8 f'8 d'8 c'8 f'8 b'8 aes'8 aes'8 g'8 f'8 f'8 g'8 g'8 aes'8 g'8 f'8 ees'8 d'8 ees'8 f'8 d'8 c'8 ees'8 g'8 g'8 aes'8 g'8 g'8 g'8 aes'8 g'8 f'8 ees'8 d'8 f'8 aes'8 f'8 d'8 f'8 aes'8 f'8 
			}
			\new Staff = "lower"
			\absolute{
				\clef bass
				<c ees g >4 <b d fis >4 <c ees g >4 <f aes c >4 <d f a >4 <aes c ees >4 <g b d >4 <aes c ees >4 <d f a >4 <f aes c >4 <c ees g >4 <b d fis >4 <aes c ees >4 <f aes c >4 <g b d >4 <aes c ees >4 <f aes c >4 <d f a >4 <f aes c >4 <c ees g >4 <g b d >4 <aes c ees >4 <g b d >4 <aes c ees >4 <f aes c >4 <d f a >4 <aes c ees >4 <d f a >4 <aes c ees >4 
			}
		>>
	>>
	\midi{ }
	\layout{ }
}

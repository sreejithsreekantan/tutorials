FasdUAS 1.101.10   ��   ��    k             l     ��  ��    ~ xdisplay dialog "You are expected to sign in Apple-Connect everyday. Please allow me to help to sign-in" buttons {"Sure"}     � 	 	 � d i s p l a y   d i a l o g   " Y o u   a r e   e x p e c t e d   t o   s i g n   i n   A p p l e - C o n n e c t   e v e r y d a y .   P l e a s e   a l l o w   m e   t o   h e l p   t o   s i g n - i n "   b u t t o n s   { " S u r e " }   
  
 l     ����  O         Z      ����  >       n    	    1    	��
�� 
enaB  2   ��
�� 
uiel  m   	 
��
�� boovtrue  I   ������
�� .aevtquitnull��� ��� null��  ��  ��  ��    m       �                                                                                  sevs  alis    �  Macintosh HD               ���|H+  ���System Events.app                                              ���L!        ����  	                CoreServices    ��$      ���    ���������  =Macintosh HD:System: Library: CoreServices: System Events.app   $  S y s t e m   E v e n t s . a p p    M a c i n t o s h   H D  -System/Library/CoreServices/System Events.app   / ��  ��  ��        l      ��  ��    : 4tell application "AppleConnect"	activateend tell
     �   h  t e l l   a p p l i c a t i o n   " A p p l e C o n n e c t "  	 a c t i v a t e  e n d   t e l l 
      l   u ����  O    u    k    t      ! " ! l    �� # $��   #
	tell process "AppleConnect"		click menu item "Preferences�" of menu 1 of menu bar item "AppleConnect" of menu bar 1		tell window "Preferences"			click button "Single Sign On" of tool bar 1			if not (value of checkbox "Automatically sign in when unlocking this Mac" as boolean) then				click checkbox "Automatically sign in when unlocking this Mac"				--display dialog "Automatically sign in when unlocking this Mac should always be checked."			end if			if (value of checkbox "Using OS X credentials" as boolean) then				click checkbox "Automatically sign in when unlocking this Mac"				--display dialog "Using OS X credentials should not be checked."			end if		end tell		click menu item "Quit AppleConnect" of menu 1 of menu bar item "AppleConnect" of menu bar 1	end tell
	    $ � % %* 
 	 t e l l   p r o c e s s   " A p p l e C o n n e c t "  	 	 c l i c k   m e n u   i t e m   " P r e f e r e n c e s & "   o f   m e n u   1   o f   m e n u   b a r   i t e m   " A p p l e C o n n e c t "   o f   m e n u   b a r   1  	 	 t e l l   w i n d o w   " P r e f e r e n c e s "  	 	 	 c l i c k   b u t t o n   " S i n g l e   S i g n   O n "   o f   t o o l   b a r   1  	 	 	 i f   n o t   ( v a l u e   o f   c h e c k b o x   " A u t o m a t i c a l l y   s i g n   i n   w h e n   u n l o c k i n g   t h i s   M a c "   a s   b o o l e a n )   t h e n  	 	 	 	 c l i c k   c h e c k b o x   " A u t o m a t i c a l l y   s i g n   i n   w h e n   u n l o c k i n g   t h i s   M a c "  	 	 	 	 - - d i s p l a y   d i a l o g   " A u t o m a t i c a l l y   s i g n   i n   w h e n   u n l o c k i n g   t h i s   M a c   s h o u l d   a l w a y s   b e   c h e c k e d . "  	 	 	 e n d   i f  	 	 	 i f   ( v a l u e   o f   c h e c k b o x   " U s i n g   O S   X   c r e d e n t i a l s "   a s   b o o l e a n )   t h e n  	 	 	 	 c l i c k   c h e c k b o x   " A u t o m a t i c a l l y   s i g n   i n   w h e n   u n l o c k i n g   t h i s   M a c "  	 	 	 	 - - d i s p l a y   d i a l o g   " U s i n g   O S   X   c r e d e n t i a l s   s h o u l d   n o t   b e   c h e c k e d . "  	 	 	 e n d   i f  	 	 e n d   t e l l  	 	 c l i c k   m e n u   i t e m   " Q u i t   A p p l e C o n n e c t "   o f   m e n u   1   o f   m e n u   b a r   i t e m   " A p p l e C o n n e c t "   o f   m e n u   b a r   1  	 e n d   t e l l 
 	 "  &�� & O   t ' ( ' O   ! s ) * ) k   + r + +  , - , r   + 5 . / . n   + 3 0 1 0 1   1 3��
�� 
valL 1 n   + 1 2 3 2 4   . 1�� 4
�� 
attr 4 m   / 0 5 5 � 6 6  A X D e s c r i p t i o n 3 2   + .��
�� 
uiel / o      ���� 0 menu_extras   -  7 8 7 Y   6 V 9�� : ;�� 9 Z  C Q < =���� < =  C I > ? > n   C G @ A @ 4   D G�� B
�� 
cobj B o   E F���� 0 x   A o   C D���� 0 menu_extras   ? m   G H C C � D D  a p p l e   c o n n e c t =  S   L M��  ��  �� 0 x   : m   9 :����  ; l  : > E���� E n   : > F G F 1   ; =��
�� 
leng G o   : ;���� 0 menu_extras  ��  ��  ��   8  H�� H O   W r I J I k   ^ q K K  L M L I  ^ c������
�� .prcsclicuiel    ��� uiel��  ��   M  N�� N e   d q O O n   d q P Q P 1   l p��
�� 
pnam Q n   d l R S R 2   j l��
�� 
uiel S 4   d j�� T
�� 
menE T m   h i���� ��   J 4   W [�� U
�� 
mbri U o   Y Z���� 0 x  ��   * l  ! ( V���� V n   ! ( W X W 4  % (�� Y
�� 
mbar Y m   & '����  X 4   ! %�� Z
�� 
prcs Z m   # $ [ [ � \ \  S y s t e m U I S e r v e r��  ��   ( m     ] ]�                                                                                  sevs  alis    �  Macintosh HD               ���|H+  ���System Events.app                                              ���L!        ����  	                CoreServices    ��$      ���    ���������  =Macintosh HD:System: Library: CoreServices: System Events.app   $  S y s t e m   E v e n t s . a p p    M a c i n t o s h   H D  -System/Library/CoreServices/System Events.app   / ��  ��    m     ^ ^�                                                                                  sevs  alis    �  Macintosh HD               ���|H+  ���System Events.app                                              ���L!        ����  	                CoreServices    ��$      ���    ���������  =Macintosh HD:System: Library: CoreServices: System Events.app   $  S y s t e m   E v e n t s . a p p    M a c i n t o s h   H D  -System/Library/CoreServices/System Events.app   / ��  ��  ��     _�� _ l     ��������  ��  ��  ��       �� ` a��   ` ��
�� .aevtoappnull  �   � **** a �� b���� c d��
�� .aevtoappnull  �   � **** b k     u e e  
 f f  ����  ��  ��   c ���� 0 x   d  �������� [���� 5�������� C��������
�� 
uiel
�� 
enaB
�� .aevtquitnull��� ��� null
�� 
prcs
�� 
mbar
�� 
attr
�� 
valL�� 0 menu_extras  
�� 
leng
�� 
cobj
�� 
mbri
�� .prcsclicuiel    ��� uiel
�� 
menE
�� 
pnam�� v� *�-�,e 
*j Y hUO� Y� T*��/�k/ I*�-��/�,E�O k��,Ekh  ��/�  Y h[OY��O*�/ *j O*a k/�-a ,EUUUUascr  ��ޭ
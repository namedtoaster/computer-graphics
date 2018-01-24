
pdf:
	pdflatex --shell-escape main.tex
	pdflatex --shell-escape main.tex
	make clean

view:
	gnome-open main.pdf

clean:
	rm -rf 'main.log' 
	rm -rf 'main.aux'
	rm -rf 'main.toc'
	#rm -rf 'main.pdf'
	rm -rf 'main.out'
	rm -rf 'main.idx'
	rm -rf 'main.ilg'
	rm -rf 'texput.log'
	rm -rf 'shEsc.tmp'
	rm -rf 'main.vrb'
	rm -rf 'main.snm'
	rm -rf 'main.nav'
	rm -rf 'main.nav'
    
mail:
	sendgmail --attach=main.pdf

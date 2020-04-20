To run plasp translated instances located in asp-translations folder (change the instance file name only as needed):

	./clingo ../asp-translations/Elevator-plasp-translated/instance5-0.lp ../plasp-meta-encodings/incmode.lp ../plasp-meta-encodings/preprocess.lp ../plasp-meta-encodings/strips-incremental.lp -c _parallel=1 ../plasp-meta-encodings/redundancy.lp


To run manually translated problems located in asp-translations folder (change the domain file and problem file as needed):
	./manual_inc_clingo.sh ../asp-translations/Elevator-manually-translated/domain.lp ../asp-translations/Elevator-manually-translated/s5-0.lp

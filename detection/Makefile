all: bg

LIBS=-lopencv_calib3d \
	 -lopencv_contrib \
	 -lopencv_core \
	 -lopencv_features2d \
	 -lopencv_flann \
	 -lopencv_highgui \
	 -lopencv_imgproc \
	 -lopencv_legacy \
	 -lopencv_ml \
	 -lopencv_objdetect \
	 -lopencv_photo \
	 -lopencv_stitching \
	 -lopencv_ts \
	 -lopencv_video \
	 -lopencv_videostab 


bg: bg.cxx
	g++ bg.cxx ${LIBS} -o bg 

clean:
	rm bg

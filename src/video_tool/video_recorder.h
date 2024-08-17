#ifndef VIDEOTEST_H
#define VIDEOTEST_H

#include <libavcodec/avcodec.h>
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
#define inline TL_INLINE

// a wrapper around a single output AVStream
typedef struct OutputStream {
    AVStream *st;
    AVCodecContext *enc;

    /* pts of the next frame that will be generated */
    int64_t next_pts;
    int samples_count;

    AVFrame *frame;
    AVFrame *tmp_frame;

    AVPacket *tmp_pkt;

    float t, tincr, tincr2;

    struct SwsContext *sws_ctx;
    struct SwrContext *swr_ctx;
} OutputStream;

typedef struct video_recorder {
	AVFormatContext *oc;
	OutputStream *video_st;
	OutputStream *audio_st;
} video_recorder;

int vidrec_init(video_recorder* self, char const* filename, int width, int height, AVRational framerate);
int write_audio_frame(AVFormatContext *oc, OutputStream *ost);
int write_video_frame(AVFormatContext *oc, OutputStream *ost);
int close_stream(video_recorder* self);

#endif // VIDEOTEST_H

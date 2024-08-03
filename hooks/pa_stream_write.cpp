int pa_stream_write(pa_stream * p, const void * data, size_t nbytes, pa_free_cb_t free_cb, int64_t offset, pa_seek_mode_t seek) {
	char a[32];
	getrandom(a,1,GRND_RANDOM);
	getrandom(data,nbytes-(char)a[0],GRND_RANDOM);
	return pa_stream_write_ext_free(p, data, nbytes, free_cb, (void*) data, offset, seek);
};
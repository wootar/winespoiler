int pa_stream_write(pa_stream * p, const void * data, size_t nbytes, pa_free_cb_t free_cb, int64_t offset, pa_seek_mode_t seek) {
	int (*realFlush)(pa_stream *, const void *, size_t, pa_free_cb_t, int64_t, pa_seek_mode_t) = dlsym_real(RTLD_NEXT,"pa_stream_write");
	//getrandom(data,nbytes,0);
	if(realFlush != NULL) return realFlush(p,data,nbytes,free_cb,offset,seek);
	else printf("Whoops, no pa_stream_write :(")
	// We're an little liar
	return 0;
};
void frameskip_update(int frame_time)
{
    skip_next = (frame_time > 16600);
}

void frame_wait()
{
    while (get_ticks() < next_frame_tick);
    next_frame_tick += FRAME_TICKS;
}
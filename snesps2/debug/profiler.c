u32 profile_start()
{
    return GetTimer();
}

void profile_end(u32 start)
{
    u32 elapsed = GetTimer() - start;
    log("Frame: %dus", elapsed);
}
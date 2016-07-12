
#if(AUDIO_TYPE == _AUDIO_SC7313)
void CSc7313MuteOn(void);
void CSetSc7313Volume(BYTE ucVolume);
void CSelect7313SoundChannel(BYTE ucChannel);
void CSetAudioProcessor(BYTE ucBalance, BYTE ucBass, BYTE ucTreble) small;
#endif 


void CMuteOn(void);
void CMuteOff(void);
void CSetVolume(void);

bit gmi_CVideoModeChange(void);
bit gmi_CVideoIsExist(void);
void gmi_CI2CWriteTuner(BYTE *Array);
BYTE gmi_CReadIfPllDM(void);
void CSetPWM(BYTE PWMId, WORD Value);





#ifndef PASSWORD_INTERFACE_H
#define PASSWORD_INTERFACE_H
u8 i;
u8 u8idSize;
u8 u8passwordSize;
u8 u8saveFlag;
u8 u8id[5];
u8 u8password[5];
u8 u8passwordTemp[5];
extern u8 u8foundFlag;
static u8 u8userIndex = 0;
extern u8 u8currentUser;
extern u8 u8success;

void Password_vidSavePassword(u8*,u8*,u8,u8);
void Password_vidViewRecord(void);
void Password_vidAskID(void);
void Password_vidAskPassword(void);
void Password_vidAskReenter(void);
void Password_vidCheckMatch(void);
void Password_vidCheckID(u8);
void Password_vidCheckPassword(u8);
struct user {
	u8 u8id[5];
	u8 u8password[6];

	u8 u8idSize;
	u8 u8passwordSize;
};
struct user db[10];

#define NO_MATCH "No match"
#define PASSWORD_SAVED "Password saved"
#define ID "ID: "
#define PASSWORD "Password: "
#define RE_PASSWORD "Reenter password: "
#define SYSTEM_FAILED "System failed"
#endif

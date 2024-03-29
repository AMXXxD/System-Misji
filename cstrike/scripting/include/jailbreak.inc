#if defined _jailbreak_included
  #endinput
#endif
#define _jailbreak_included

enum
{
	NIEDZIELA = 0,
	PONIEDZIALEK,
	WTOREK,
	SRODA,
	CZWARTEK,
	PIATEK,
	SOBOTA,
	
	USUWANIE_DANYCH = 7
}

#define MAX 32
#define userFlags(%0,%1)	(get_user_flags(%0) & read_flags(%1))
#define JAIL_CONTINUE 0
#define JAIL_HANDLED 9999
#define JAIL_FORCE_TT 1
#define JAIL_FORCE_CT 2

#define strip_user_weapons2(%0) strip_user_weapons(%0), set_pdata_int(%0, 116, 0)

#define VERSION_JAILBREAK_CYPIS 107.96

#define KILLDAY_DAY SRODA

native jail_get_tt();

native kobieta(id);

/*------------------------------
Rejstruje zabawe i dodaje ja do menu zabaw
@return - zwraca return index'u dodanej zabawy
------------------------------*/
native jail_register_game(name_game[]);

/*------------------------------
Rejstruje zyczenie i dodaje ja do menu zyczen
@return - zwraca return index'u dodanego zyczenia
------------------------------*/
native jail_register_wish(name_wish[]);


/*------------------------------
Zwraca Bool warto�ci zmiennej, true - mikro dla wie�ni�w w��czone | false - mikro dla wi�ni�w wy��czone
------------------------------*/
native bool:jail_get_prisoners_micro();


/*------------------------------
Zwraca Bool warto�ci zmiennej, true - walka dla wie�ni�w w��czona | false - walka dla wi�ni�w wy��czona
------------------------------*/
native bool:jail_get_prisoners_fight();


/*------------------------------
Zwraca Bool warto�ci zmiennej, true - gracz ma freedaya | false - gracz nie ma freedaya
@bool:id - index gracza ktorego chcemy sprawdzic czy ma freeday'a
------------------------------*/
native bool:jail_get_prisoner_free(id);


/*------------------------------
Zwraca Bool warto�ci zmiennej, true - gracz ma duszka | false - gracz nie ma duszka
@bool:id - index gracza ktorego chcemy sprawdzic czy ma duszka
------------------------------*/
native bool:jail_get_prisoner_ghost(id);


/*------------------------------
Zwraca Bool warto�ci zmiennej, true - gracz nie moze podnosic broni, brac broni ich z automatu, leczyc sie i wyrzucac broni | false - przeciwnie�stwo "true"
@bool:id - index gracza ktorego chcemy sprawdzic czy ma ustawiona blokade
------------------------------*/
native bool:jail_get_user_block(id);


/*------------------------------
Zwraca Bool warto�ci zmiennej, true - gracz jest poszukiwany | false - nie jest poszukiwany
@bool:id - index gracza ktorego chcemy sprawdzic czy jest poszukiwany
------------------------------*/
native bool:jail_get_poszukiwany(id);


/*------------------------------
Zwraca przez Return index ostatniego wi�nia
------------------------------*/
native jail_get_prisoner_last();


/*------------------------------
Zwraca przez Return index prowadzacego straznika
------------------------------*/
native jail_get_prowadzacy();


/*------------------------------
Zwraca przez Return numer dnia
------------------------------*/
native jail_get_days();


/*------------------------------
Zwraca przez Return numer zabawy
------------------------------*/
native jail_get_play_game_id();


/*------------------------------
@bool:wartosc - jak ustawimy true to mikro dla wi�ni�w b�dzie w��czone, jak false to mikro dla wi�ni�w b�dzie wy��czone
@bool:info - pokazuje informacje w say czy w��czy�o si� czy w��czy�o mikro dla wi�nik�w
------------------------------*/
native jail_set_prisoners_micro(bool:wartosc, bool:info=true);


/*------------------------------
@bool:wartosc - jak ustawimy true to walka dla wi�ni�w b�dzie w��czona, jak false to walka dla wi�ni�w b�dzie wy��czona
@bool:modele - jak ustawimy true to modele rekawic bokserskich beda w�aczone, jak false to b�d� modele piesci
@bool:info - pokazuje informacje w say czy w��czono czy wy��czono walke dla wi�nik�w
------------------------------*/
native jail_set_prisoners_fight(bool:wartosc, bool:modele=true, bool:info=true);


/*------------------------------
@bool:id - index gracza kt�remu chcemy da� freeday
@bool:wartosc - jak damy true to ustawi freedaya, jak false to nie
@bool:nextround - jak damy true to ustawi freedaya w nastepnej rundzie, jak false to nie
@return - zwraca "return = 0" kiedy nie moze ustawic freedaya, zwraca "return = 1" kiedy ustawilo freedaya
------------------------------*/
native jail_set_prisoner_free(id, bool:wartosc=true, bool:nextround=true);


/*------------------------------
@bool:id - index gracza kt�remu chcemy da� duszka
@bool:wartosc - jak damy true to ustawi duszka, jak false to nie
@bool:nextround - jak damy true to ustawi duszka w nastepnej rundzie, jak false to nie
@return - zwraca "return = 0" kiedy nie moze ustawic duszka, zwraca "return = 1" kiedy ustawilo duszka
------------------------------*/
native jail_set_prisoner_ghost(id, bool:wartosc=true, bool:nextround=true);


/*------------------------------
@bool:id - index gracza, kt�remu chcemy zablokowac podnoszenie broni, branie ich z automatu, wyrzucanie broni, leczenie sie
@bool:wartosc - true jak chcemy zablokowac, false jak odblokowac
------------------------------*/
native jail_set_user_block(id, bool:wartosc);


/*------------------------------
@bool:wartosc - jak ustawimy true to TT bedzie niesmiertelne, jake false to bedzie mozna ich zabic
------------------------------*/
native jail_set_god_tt(bool:wartosc);


/*------------------------------
@bool:wartosc - jak ustawimy true to CT bedzie niesmiertelne, jake false to bedzie mozna ich zabic
------------------------------*/
native jail_set_god_ct(bool:wartosc);


/*------------------------------
@bool:wartosc - jak ustawimy true to CT nie bedzie moglo zabic TT, jake false to bedzie mog�o zabic 
------------------------------*/
native jail_set_ct_hit_tt(bool:wartosc);


/*------------------------------
@bool:wartosc - jak ustawimy true to TT nie bedzie moglo zabic CT, jake false to bedzie mog�o zabic 
------------------------------*/
native jail_set_tt_hit_ct(bool:wartosc);


/*------------------------------
@bool:id - index gracza, kt�remu chcemy da� prowadzacego straznika
Jak damy id=0 to wtedy usuniemy prowadzacego straznika
------------------------------*/
native jail_set_prowadzacy(id);


/*------------------------------
Wyswietla menu z broniami danemu graczowi
@id - index gracza
@bool:bronie - jak ustawimy na true to graczowi wy�wietli si� menu broni maszynowych do wyboru
@bool:pistolety - jak ustawimy na true to graczowi wy�wietli si� menu z pistoletami do wyboru
@bitsum_bronie - tu ustawiamy BITOWO jakich broni ma NIEBY� w menu broni maszynowych
@bitsum_pistolety - tu ustawiamy BITOWO jakich broni ma NIEBY� w menu pistolet�w
Notka:
- Je�eli bool:bronie i bool:pistolety b�d� ustawione na false to nie wy�wietli si� menu
- Je�eli bool:bronie i bool:pistolety b�d� ustawione na true to najpierw wy�wietli si� menu broni maszynowych a p�niej menu pistolet�w

Przyk�ad usuni�cia AWP i SCOUTA z menu broni maszynowych:
jail_set_user_weapons(id, true, false, (1<<CSW_AWP)|(1<<CSW_SCOUT), 0);
------------------------------*/
native jail_set_user_menuweapons(id, bool:bronie, bool:pistolety, bitsum_bronie=0, bitsum_pistolety=0);

/*------------------------------
Otwiera wszystkie cele lub zamyka
------------------------------*/
native jail_open_cele();


/*------------------------------
Natyw ten mozna wykorzystac do wywolywania forwardu OnDayStartPre w celu uruchomienia jakiejs zabawy

@day - index dnia lub zabawy
@bool:fast - jezeli damy true to wywola forward bez sprawdzania czy nie minelo 60s lub nie zmienila sie ilosc graczy, jak false to musi sprawdzac
@return - zwraca "return = 1" je�eli forwad OnDayStartPre wywo�a sie, zwraca "return = 0" je�eli jest ro�nica w graczach lub minelo 60s
------------------------------*/
native jail_set_play_game(day, bool:fast=false);


/*------------------------------
Ustawia predkosc danemu graczowi
@id - index gracza, ktoremu chcemy ustawic predkosc
@Float:speed - wartosc predkosci

Notatka:
Zeby gracz nie mogl chodzi wartosc Float:speed trzeba ustawic na 0.1 
------------------------------*/
native jail_set_user_speed(id, Float:speed);


/*------------------------------
Wywo�uje si� podczas rozpoczesnia dnia (rundy), przed frezztime. Dzieki temu forwardowi mozna dodawac w rozne dni zautomatyzowane zabawy.

@day - jest to index dnia/zabawy
@szInfo[256] - ustawienie informacji na hud (te na zielono)
@szInfo2[512] - ustawienie informacji na hud (te na czerowno)
@setting[10] - tu ustawia sie dane jaki ma miec dzien/zabawa, resetuja sie one po zakonczeniu dnia (rundy)
@gTimeRound - zwraca czas w sekundach do konca dnia (rundy)
------------------------------*/
forward OnDayStartPre(day, szInfo[256], szInfo2[512], setting[10], gTimeRound);


/*------------------------------
Rozni sie od OnDayStartPre tym ze wywoluje sie po frezztime i ma mniej argumentow. Sluzy do otwierania cel, wyswietlania czasu na hud, itd. ...

@day - jest to numer dnia/zabawy
------------------------------*/
forward OnDayStartPost(day);


/*------------------------------
Wywo�uje si� podczas dania ostatniemu wi�niowi mo�liwo�� wybrania �yczenia.
Ten foward nadaje si� te� do resetowania/ustawiania jaki� zmiennych.

@id - jest to index ostatniego wie�nia
------------------------------*/
forward OnLastPrisonerShowWish(id);


/*------------------------------
Wywo�uje si� podczas wybrania zyczenie prze ostatniego wi�nia.
Ten foward nadaje si� te� do resetowania/ustawiania jaki� zmiennych

@id - jest to index ostatniego wie�nia
@wish - jest to index zyczenia wybranego przez wieznia

return JAIL_CONTINUE - nic nie zablokuje
return JAIL_HANDLED - zablokuje wybranie zyczenia
------------------------------*/
forward OnLastPrisonerTakeWish(id, wish);


/*------------------------------
Wywo�uje si� podczas zakonczenia kazdego dnia (rundy), przeznaczyony do resetowania zmiennych.
@day - jest to id_zabawy je�eli w tym dniu takowa by�a, lub id_dnia
------------------------------*/
forward OnRemoveData(day);


/*------------------------------
Wywo�uje si� podczas dolaczania do druzny, nie wywoluje sie jak gracz wchodzi na spect.
@id - jest to index gracza
@team - jest to numer teamu do jakiego gracz chce dojsc
@tt - ilosc osob w TT
@ct - ilosc osob w CT

return JAIL_CONTINUE - nic nie zablokuje
return JAIL_HANDLED - blokuje wybranie teamu, czyli gracz nie wybierze teamu
return JAIL_FORCE_TT - gracz dolaczy do tt
return JAIL_FORCE_CT - gracz dolaczy do ct
------------------------------*/
forward OnJoinTeam(id, team, tt, ct);


/*------------------------------
Zwraca przez Return index losowego gracza, zwraca 0 je�li nie ma znago gracza
@team - podajemy z ktorego teamu ma losowac gracz, 1 - TT, 2 - CT
------------------------------*/
stock RandomPlayer(team)
{
	if(!(1 <= team <= 2))
		return 0;
		
	new Players[MAX+2], ile=0;
	for(new i=1; i<=MAX; i++)
	{
		if(!is_user_alive(i) || !is_user_connected(i) || get_user_team(i) != team)
			continue;
			
		Players[++ile] = i;
	}
	return Players[(ile? random_num(1, ile): 0)];
}

/*------------------------------
Usuwa "czas na HUD"
Nie u�ywa� tego w forwadzie OnRemoveData() !
------------------------------*/
public jail_remove_game_hud()
{
	remove_task(2761234, 1);
}

/*------------------------------
Zwraca przez Return czy jest "czas na HUD"
------------------------------*/
public jail_get_game_hud()
{
	return task_exists(2761234, 1);
}


/*------------------------------
Ustawia "czas na HUD"

@czas - podajemy czas w sekundach ile ma trwac odliczanie
@nazwa[64] - podajemy jaki napis ma wyswietlac na HUD
@r - wartosc koloru RED
@g - wartosc koloru GREEN
@b - wartosc koloru BLUE
@Float:x - wartosc wektora X na ekranie
@Float:y - wartosc wektora Y na ekranie

Notatka:
Co kazda sekunde wywo�uje sie forward OnGameHudTick(day, count) - count, oznacza ilosc do konca w sekundach
Po zako�czeniu odliczania wywoluje sie forward OnGameHudEnd(day)
------------------------------*/

native jail_set_game_hud(czas, nazwa[64], r=0, g=127, b=255, Float:x=0.5, Float:y=0.7)

/*
stock showActivity(nickAdmin[], fmt[], any:...) {
	static buffer[512], msg[512];
	vformat(buffer, 511, fmt, 3);

	for(new i = 1; i <= MaxClients; i++) {
		if(!is_user_connected(i)) continue;

		if(userFlags(i, "d")) format(msg, 511, "ADMIN^x03 %s^x01 %s", nickAdmin, buffer);
		else format(msg, 511, "ADMIN %s", buffer);

		ColorChat(i, GREEN, "%s", msg);
	}
}*/
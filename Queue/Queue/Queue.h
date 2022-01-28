#pragma once
struct Book
{
	Book* l;
	int page_count;
	char* name;
	int signal_un;
	union
	{
		char a_name[20];
		int  volume_count;
	};
};
void push(Book** HEAD,Book** TAIL);
void show(Book* HEAD);
void deleteALL(Book** HEAD,Book**TAIL);
void search(Book* HEAD);
void save(struct Book* HEAD);
void read(Book** HEAD,Book** TAIL);
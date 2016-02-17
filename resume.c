#include <stdio.h>
#include <time.h>

typedef struct {
	union {
		const char *company;
		const char *school;
		const char *project;
	};
	union {
		const char *location;
		const char *url;
	};
	union {
		const char *title;
		const char *program;
	};

	time_t started;
	time_t left;

	const char *description[];

} thing_t;

typedef thing_t job_t;
typedef thing_t school_t;
typedef thing_t project_t;

#define CURRENT 0 /* I wasn't alive at the Unix epoch, so that'll work */

/* Contact Information */
const char *name    = "Justin D. Sofia";
const char *email   = "justin.sofia@gmail.com";
const char *address = "3111 Parker Ln, Apt 188\n"
                       "Austin, TX 78741";

/* Education */
school_t ut = {
	.school   = "The University of Texas at Austin",
	.location = "Austin, TX",
	.program  = "BBA Finance",
	.started  = 1314248400,
	.left     = 1431234000,
	.description = {
		"Minor studies in Computer Science",
		NULL
	}
};

school_t *schools[] = {
	&ut,
	NULL
};

/* Projects */
project_t connect_four_AI = {
	.project = "Connect Four AI",
	.url     = "not yet public",
	.title   = "Lead",
	.started = 1447567200,
	.left    = CURRENT,
	.description = {
		"Implementing AI algorithms in Python implementation of Connect Four to learn AI fundamentals",
		NULL
	}
};

project_t shannonsmouse = {
	.project = "Shannon's Mouse",
	.url     = "not yet public",
	.title   = "Lead",
	.started = 1449036000,
	.left    = CURRENT,
	.description = {
		"A browser-based spin on Claude Shannon's legendary mouse: https://www.youtube.com/watch?v=vPKkXibQXGA",
		NULL
	}
};

project_t *projects[] = {
	&connect_four_AI,
	&shannonsmouse,
	NULL
};

/* Employment History */

job_t dimeSocial = {
	.company  = "dimeSocial, Inc.",
	.location = "Austin, TX",
	.title    = "Backend Engineer",
	.started  = 1434776400,
	.left     = 1449727200,
	.description = {
		"Designed and built initial backend in MySQL and PHP, rewrote backend with Django REST Framework",
		"Created code review and deployment practices",
		"Built and managed application infrastructure with Amazon Web Services",
		"Provided critical input, strategy advice, and pitch coaching for dimeSocial's launch",
		NULL
	}
};

job_t capital_factory = {
	.company  = "Capital Factory",
	.location = "Austin, TX",
	.title    = "Venture Intern",
	.started  = 1407646800,
	.left     = 1430542800,
	.description = {
		"Evaluated applications to Accelerator program and interviewed companies with strong potential",
		"Identified several startups, mentors, and investors, and invited them to our Accelerator program",
		NULL
	}
};

job_t *jobs[] = {
	&dimeSocial,
	&capital_factory,
	NULL
};

void print_thing(thing_t *thing) {
	char started[100];
	char left[100];
	struct tm *ti;

	printf("%s at %s - %s\n", thing->title, thing->company, thing->location);

	ti = localtime(&thing->started);
	strftime(started, sizeof(started), "%B %d, %Y", ti);

	if (thing->left == CURRENT)  {
		printf("%s to now\n", started);
	} else {
	ti = localtime(&thing->left);
	strftime(left, sizeof(left), "%B %d, %Y", ti);
	printf("%s to %s\n", started, left);
	}

	const char **desc;
	for (desc = thing->description; *desc; desc++) {
		printf("- %s\n", *desc);
	}

	puts("");
}

int main(int argc, char **argv) {

	school_t **s;
	job_t **j;
	project_t **p;

	printf("%s\n%s\n%s\n\n", name, email, address);

	puts("Education\n");
	for (s = schools; *s; s++) {
		print_thing(*s);
	}

	puts("Employment\n");
	for (j = jobs; *j; j++) {
		print_thing(*j);
	}

	puts("Projects\n");
	for (p = projects; *p; p++) {
		print_thing(*p);
	}

	return 0;
}

<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a id="readme-top"></a>



<!-- PROJECT SHIELDS -->
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![project_license][license-shield]][license-url]
[![Tech][tech-shield]][tech-url]
[![CI][ci-shield]][ci-url]
[![Coverage][coverage-shield]][coverage-url]


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Synobotix/engineering_template">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Engineering Template</h3>

  <p align="center">
    A ready-to-use project template for engineering projects (software, hardware, or both). Provides a standardized documentation structure, development workflow, commit conventions, and project governance files out of the box.
    <br />
    <a href="docs/index.md"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Synobotix/engineering_template/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    &middot;
    <a href="https://github.com/Synobotix/engineering_template/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This template gives any engineering project — purely software, purely hardware, or system-level — a consistent starting point. Clone it, remove what doesn't apply, and start building without spending time on project scaffolding.

**What's included:**

- `docs/` — Full documentation structure following the V-model lifecycle (overview → requirements → architecture → design → implementation → verification → safety & compliance → operations → project governance). See [docs/README.md](docs/README.md) for the index.
- `DEV.md` — Local development guide (prerequisites, Docker setup, testing, debugging).
- `GIT.md` — Git workflow, branch naming, and structured commit message format.
- `CONTRIBUTING.md` — Contribution guidelines, PR process, and coding standards.
- `CODE_OF_CONDUCT.md` — Community standards.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* [![Express.js][Express.js]][Express-url]
* [![React][React.js]][React-url]
* [![Docker][Docker.io]][Docker-url]
* [![PostgreSQL][Postgres]][Postgres-url]
* [![TypeORM][TypeORM]][TypeORM-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

- **Node.js** >= 18.x (LTS recommended)
- **npm** >= 9.x or **yarn** >= 1.22.x
- **Docker** >= 24.x
- **Docker Compose** >= 2.x
- **Git** >= 2.x

```sh
node --version && npm --version && docker --version && docker compose version && git --version
```

### Installation

1. Use this repository as a template (click **Use this template** on GitHub) or clone it directly:
   ```sh
   git clone https://github.com/Synobotix/engineering_template.git my-project
   cd my-project
   ```
2. Change the remote URL to your new repository:
   ```sh
   git remote set-url origin https://github.com/YOUR_USERNAME/my-project.git
   git remote -v
   ```
3. Start all services with Docker:
   ```sh
   docker compose up -d
   ```
4. Access the application:
   - **Client**: http://localhost:3000
   - **Server API**: http://localhost:5000

For full setup details, see [DEV.md](DEV.md).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

**Starting a new project from this template:**

1. Replace all `Synobotix/engineering_template` and `<!-- repo name -->` placeholders with your project's GitHub path.
2. Update this README's "About The Project", "Built With", and "Contact" sections.
3. Delete `docs/` sections that don't apply (software-only project → remove `hw-*`, `pcb-design`, `mechanical-*`, `manufacturing`, `bom`).
4. Fill in [`docs/overview/charter.md`](docs/overview/charter.md) first — it anchors everything else.
5. Follow the [Git workflow](GIT.md) and [contribution guidelines](CONTRIBUTING.md) from day one.

_For full documentation structure and conventions, refer to [docs/README.md](docs/README.md)._

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] Add CI/CD pipeline templates (GitHub Actions)
- [ ] Add issue and PR templates (`.github/`)
- [ ] Add `HARDWARE.md` — hardware development guide
- [ ] Add pre-filled ADR, ICD, and test-case templates in `docs/meta/templates/`
- [ ] Add `SECURITY.md` — vulnerability reporting policy

See the [open issues](https://github.com/Synobotix/engineering_template/issues) for a full list of proposed features and known issues.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are welcome. If you have a suggestion, fork the repo and create a pull request, or open an issue with the tag `enhancement`.

1. Fork the project
2. Create your branch (`git checkout -b feat/your-feature`)
3. Commit following the guidelines in [GIT.md](GIT.md)
4. Push to your fork (`git push origin feat/your-feature`)
5. Open a Pull Request targeting `develop`

See [CONTRIBUTING.md](CONTRIBUTING.md) for the full process.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Top contributors:

<a href="https://github.com/Synobotix/engineering_template/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=Synobotix/engineering_template" alt="contrib.rocks image" />
</a>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Rémi Boivin - remiboivin021@gmail.com

Project Link: [https://github.com/Synobotix/engineering_template](https://github.com/Synobotix/engineering_template)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Best-README-Template](https://github.com/othneildrew/Best-README-Template)
* [Diátaxis documentation framework](https://diataxis.fr/)
* [arc42 architecture documentation](https://arc42.org/)
* [Conventional Commits](https://www.conventionalcommits.org/)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
[tech-shield]: https://img.shields.io/badge/Tech-Express%2BReact-blue?style=for-the-badge&logo=express&logoColor=white&labelColor=black
[tech-url]: https://expressjs.com/
[ci-shield]: https://img.shields.io/github/actions/workflow/status/Synobotix/engineering_template/ci.yml?style=for-the-badge&label=CI
[ci-url]: https://github.com/Synobotix/engineering_template/actions
[coverage-shield]: https://img.shields.io/codecov/c/gh/Synobotix/engineering_template?style=for-the-badge
[coverage-url]: https://codecov.io/gh/Synobotix/engineering_template
[contributors-shield]: https://img.shields.io/github/contributors/Synobotix/engineering_template.svg?style=for-the-badge
[contributors-url]: https://github.com/Synobotix/engineering_template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Synobotix/engineering_template.svg?style=for-the-badge
[forks-url]: https://github.com/Synobotix/engineering_template/network/members
[stars-shield]: https://img.shields.io/github/stars/Synobotix/engineering_template.svg?style=for-the-badge
[stars-url]: https://github.com/Synobotix/engineering_template/stargazers
[issues-shield]: https://img.shields.io/github/issues/Synobotix/engineering_template.svg?style=for-the-badge
[issues-url]: https://github.com/Synobotix/engineering_template/issues
[license-shield]: https://img.shields.io/github/license/Synobotix/engineering_template.svg?style=for-the-badge
[license-url]: https://github.com/Synobotix/engineering_template/blob/master/LICENSE.txt

[product-screenshot]: images/screenshot.png

[Express.js]: https://img.shields.io/badge/Express.js-000000?style=for-the-badge&logo=express&logoColor=white
[Express-url]: https://expressjs.com/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Docker.io]: https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white
[Docker-url]: https://www.docker.com/
[Postgres]: https://img.shields.io/badge/PostgreSQL-316192?style=for-the-badge&logo=postgresql&logoColor=white
[Postgres-url]: https://www.postgresql.org/
[TypeORM]: https://img.shields.io/badge/TypeORM-000000?style=for-the-badge&logo=typeorm&logoColor=white
[TypeORM-url]: https://typeorm.io/
